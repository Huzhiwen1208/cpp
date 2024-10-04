import os
import sys
import time
import argparse

time_now = time.strftime("%Y-%m-%d %H:%M", time.localtime())
def create_cpp_template(relative_path, item_name, cpp_template):
    # 获取绝对路径
    abs_path = os.path.abspath(relative_path)
    
    # C++ 文件路径
    cpp_file_path = os.path.join(abs_path, f"{item_name}.cpp")
    
    # 创建并写入 C++ 模板文件
    with open(cpp_file_path, "w") as cpp_file:
        cpp_file.write(cpp_template)
    
    print(f"C++ 模板文件已创建在: {cpp_file_path}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Create a C++ template file in the specified directory.")
    parser.add_argument("--dir", required=True, help="Relative path to the directory where the C++ template file will be created.")
    parser.add_argument("--name", required=True, help="Name of the C++ template file.")
    
    args = parser.parse_args()
    test_name = args.name
    cpp_template = f"""/**
* author: Jackhu
* time: {time_now}
* content: 
* description: 
*/
#include <bits/stdc++.h>
using namespace std;

void {test_name}_test() {{
    printf("\\033[35m>>>>>>>>>>> Test op_overload_test Start <<<<<<<<<<<\\033[0m\\n");
    // your code here...
    printf("\\033[35m>>>>>>>>>>> Test op_overload_test Passed <<<<<<<<<<<\\033[0m\\n");
}}
"""

    create_cpp_template(args.dir, args.name, cpp_template)
    # 打开文件
    os.system(f"code {args.dir}/{args.name}.cpp")