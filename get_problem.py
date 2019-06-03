from shutil import copyfile
from os import mkdir
from bs4 import BeautifulSoup as bs
import requests
import os


def make_dir(loc):
    try:
        mkdir(loc)
        return True
    except FileExistsError:
        return False
    
    
def get_problem(pnum):
    pdir = "problems/ID{:03}".format(pnum)
    
    if os.path.exists(pdir):
        return False
    
    url = f"https://projecteuler.net/problem={pnum}"
    page = requests.get(url)
    sp = bs(page.content, 'html.parser')
    
    title = sp.find('h2').text
    description = sp.find('div', {'class' : 'problem_content'})
    
    try:
        difficulty = int(sp.find('span').text.split(';')[-1][18:-1])
    except Exception as e:
        difficulty = 0
        
        
    make_dir(pdir)
    
    copyfile('management/templates/main.cpp', f'{pdir}/main.cpp')
    
    pmd = ''
    with open('management/templates/problem.md') as f:
        pmd = f.read()
    
    pmd = pmd.format(title=title, id=pnum, diff=difficulty, link = url, description=description)
    
    with open(f'{pdir}/problem.md', 'w', encoding="utf-8") as f:
        f.write(pmd)
    
    return True
    




for i in range(10):
    get_problem(i+1)