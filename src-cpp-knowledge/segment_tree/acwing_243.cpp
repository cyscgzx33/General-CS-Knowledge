#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100001;
typedef long long ll;
ll A[N];

struct Node {
    ll l, r; /* left and right bounds of the interval */
    ll sum;  /* interval sum */
    ll tag;  /* delay tag */
} tree[4*N];

// Update father node using processed son nodes
void pushUp(int rt) {
    tree[rt].sum = tree[rt<<1].sum + tree[rt<<1|1].sum;
}

// Build the tree recursively
void build(int rt, int start ,int end) {
    tree[rt].l = start;
    tree[rt].r = end;
    tree[rt].tag = 0;
    if (start == end)
        tree[rt].sum = A[start];
    else {
        int mid = (start + end) >> 1;
        build(rt<<1, start, mid);
        build(rt<<1|1, mid+1, end);
        pushUp(rt);
    }
}

// Update a single point
void update(int rt, int pos, int val) {
    if (tree[rt].l == tree[rt].r) {
        A[pos] = val;
        tree[rt].sum = val;
        return;
    }
    
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if (pos <= mid)
        update(rt<<1, pos, val);
    else
        update(rt<<1|1, pos, val);
    pushUp(rt);
}

// Update tag info of son nodes, for the range modification
void pushDown(int rt) {
    if (tree[rt].tag == 0) return;

    int mid = (tree[rt].l + tree[rt].r) >> 1;
    int left = rt << 1, right = rt << 1 | 1;
    // a lazy token
    ll lazy = tree[rt].tag;
    // update tags for left & right sons
    tree[left].tag += lazy;
    tree[right].tag += lazy;
    // update sums for left * right sons
    tree[left].sum += lazy * (mid - tree[rt].l + 1);
    tree[right].sum += lazy * (tree[rt].r - mid);
    // clear the tag of rt
    tree[rt].tag = 0;
}

// Add delta to each element in the range [start, end]
void updateRange(int rt, int start, int end, ll delta) {
    // situation 1: [l, r] is a subset of [start, end]
    //        [l  r]
    // [start          end]
    if (start <= tree[rt].l && end >= tree[rt].r) {
        tree[rt].sum += (tree[rt].r - tree[rt].l + 1) * delta;
        tree[rt].tag += delta;
        return;
    }

    // situation 2: not a subset
    // step I: process the tag info
    pushDown(rt);
    // step II: update ranges in the son nodes
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    if (start <= mid) // ==> there's some range in the left son needs to be updated
        updateRange(rt<<1, start, end, delta);
    if (end >= mid + 1) // ==> there's some range in the right son needs to be updated
        updateRange(rt<<1|1, start, end, delta);
    // step III: update rt info after the sons' info updated
    pushUp(rt);
}

// Query sum of range [start, end] (because we have tag, we also do the modification during the query)
ll queryRange(int rt, int start, int end) {
    if (start <= tree[rt].l && end >= tree[rt].r)
        return tree[rt].sum;
    pushDown(rt);
    int mid = (tree[rt].l + tree[rt].r) >> 1;
    ll res = 0;
    if (start <= mid) res += queryRange(rt<<1, start, end);
    if (end >= mid + 1) res += queryRange(rt<<1|1, start, end);
    return res;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &A[i]);
    build(1, 1, n);

    for (int i = 1; i <= m; i++) {
        char ch;
        cin >> ch;
        if (ch == 'Q') {
            int start, end;
            scanf("%d %d", &start, &end);
            printf("%lld\n", queryRange(1, start, end));
        }
        else {
            int start, end;
            ll delta;
            scanf("%d %d %lld", &start, &end, &delta);
            updateRange(1, start, end, delta);
        }
    }
    return 0;
}