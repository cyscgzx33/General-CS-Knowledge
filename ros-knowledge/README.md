# Useful `ros` commands/techniques

## How to ignore some package(s) when executing catkin_make
* Using `CATKIN_IGNORE` to achieve this.
* [My understanding] simply `touch CATKIN_IGNORE` under the `~/catkin_ws/src/<specific-pkg>`; at the build time, the compiler would automatically ignore the `<specific-pkg>`.
* [Reference] https://answers.ros.org/question/208180/how-to-use-catkin_ignore-file-correctly/.