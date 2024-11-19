import os
import re

def rename_items(directory, target_string, replacement_string):
    for root, dirs, files in os.walk(directory, topdown=False):
        # 重命名文件
        for file_name in files:
            if target_string in file_name:
                new_file_name = file_name.replace(target_string, replacement_string)
                old_file_path = os.path.join(root, file_name)
                new_file_path = os.path.join(root, new_file_name)
                os.rename(old_file_path, new_file_path)
                print(f"Renamed file '{old_file_path}' to '{new_file_path}'")

        # 重命名文件夹
        for dir_name in dirs:
            if target_string in dir_name:
                new_dir_name = dir_name.replace(target_string, replacement_string)
                old_dir_path = os.path.join(root, dir_name)
                new_dir_path = os.path.join(root, new_dir_name)
                os.rename(old_dir_path, new_dir_path)
                print(f"Renamed directory '{old_dir_path}' to '{new_dir_path}'")

if __name__ == "__main__":
    directory = r"C:\Users\86177\Downloads\learning_material\本科\大二上\数据结构与算法"  # 替换为你的目录路径
    target_string = "裘一涵"  # 替换为你要查找的字符串
    replacement_string = "task"  # 替换为你要替换的字符串
    rename_items(directory, target_string, replacement_string)
    print("重命名完成！")