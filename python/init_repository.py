import pandas as pd
from shutil import copyfile, rmtree
from os import mkdir
import numpy as np
from states import states

df = pd.read_csv("database.csv")

try:
    mkdir("../problems")
except FileExistsError:
    pass

f = open("templates/problem.md")
template_prob = f.read()
f.close()


for index, row in df.iterrows():
    
    dirname = "ID000"
    id = str(index)
    dirname = "../problems/" + dirname[:-len(id)] + id
    
    
    try:
        mkdir(dirname)
        copyfile("templates/main.cpp", dirname +"/main.cpp")
        copyfile("templates/state.txt", dirname +"/state.txt")
        
        outs = template_prob.format(title=row['Title'],
                                    state=states[row['State']][0],
                                    state_text=states[row['State']][1],
                                    id=index + 1,
                                    link=f"https://projecteuler.net/problem={index+1}",
                                    solution=row['Solution']
                                    ) 
        f = open(dirname + "/Problem.md", "w")
        f.write(outs)
        f.close()
        
    except FileExistsError:
        pass

    if index > 5:
        #break
        pass