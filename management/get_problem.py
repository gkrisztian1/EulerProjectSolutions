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
    dirname = "ID{:03}".format(pnum)
    pdir = f"problems/{dirname}"
    
    if os.path.exists(pdir):
        print(f'Problem {pnum:<3} is already synced.')
        return False
    else:
        print(f'Syncing {pnum:<3} ', end='')
    
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

    pcm = ''
    with open('management/templates/CMakeLists.txt') as f:
        pcm = f.read()

    pcm = pcm.format(id=dirname)
    with open(f'{pdir}/CMakeLists.txt', 'w') as f:
        f.write(pcm)
    
    print('Done')
    return True
    



print("Write -1 to quit.")
while True:
    pn = int(input("Problem ID: "))
    if pn == -1:
        print('Exit.')
        break
    else:
        get_problem(pn)
