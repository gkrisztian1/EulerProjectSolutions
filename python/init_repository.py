import pandas as pd
from shutil import copyfile, rmtree
from os import mkdir
import numpy as np
from states import *
from bs4 import BeautifulSoup as bs
import requests

def make_dir(loc):
    try:
        mkdir(loc)
        return True
    except FileExistsError:
        return False

url = "https://projecteuler.net/recent"
page = requests.get(url)
soup = bs(page.content, 'html.parser')
numproblem = int(soup.find("td").text)





root = "../problems"
make_dir(root)
        
        
        
for i in range(1, numproblem + 1):
    
    url = f"https://projecteuler.net/problem={i}"
    page = requests.get(url)
    soup = bs(page.content, 'html.parser')
    
    problem_title = soup.findAll("h2")[0].get_text()
    problem_difficulty = soup.findAll("span")[0].get_text().split(";")[-1][18:-1]
    
    print(f"{i:>3}|{problem_title:<50}|{problem_difficulty:>3}|")
    
    pdir = root + "/" + "ID{:03}".format(i)
    make_dir(pdir)
    
    
    if i > 10:
        break
    
