import pandas as pd
from shutil import copyfile, rmtree
from os import mkdir
import numpy as np

df = pd.read_csv("database.csv")
mk = pd.read_csv("templates/state_def.csv")

try:
    mkdir("../problems")
except FileExistsError:
    pass

f = open("../Readme.md", "w")

f.write("# My Solution for Euler Project Problems\n\n")
        
        
        
        
f.write("## Statistics\n\n")
f.write("|State|Problem|Number|%|\n")
f.write("|-|-|-|-|\n")

for index, row in mk.iterrows():
    line = f"{row['emoji']} | {row['text']} | 0 | 0.00\n"
    f.write(line)





f.write("## Problem Difficulty Ratings\n\n")
f.write("|Difficulty Rating|Problems Available|Problems Solved|Progress|\n")
f.write("|-|-|-|-|\n")

diffs = np.linspace(5, 100, 20)

for i in diffs:
    
    available_problems = df[df["Difficulty"] == i].shape[0]
    solved_problems = 0
    progress = solved_problems / available_problems
    
    f.write(f"{i} %| {available_problems} | {solved_problems} | {progress:.2f} %\n")
        

















states = {
        "solved": ":white_check_mark:",
        "notsolved":":x:",
        "inprogress": ":large_blue_circle:",
        "intact":":cloud:"
        }

for key in states.keys():
    df.loc[df["State"] == key, "State"] = states[key]

f.write("## Problems\n")
f.write("ID | Title | Difficulty | State | Solution |\n")
f.write("|-|-|-|-|-|\n")

'''
for index, row in df.iterrows():
    
    dirname = "ID000"
    id = str(index)
    dirname = "../problems/" + dirname[:-len(id)] + id
    
    
    try:
        mkdir(dirname)
        copyfile("templates/main.cpp", dirname +"/main.cpp")
        copyfile("templates/state.txt", dirname +"/state.txt")
        copyfile("templates/solution.txt", dirname +"/solution.txt")
        
    except FileExistsError:
        pass

    
    if index > 5:
        break
'''
    
f.close()
#rmtree("../problems")