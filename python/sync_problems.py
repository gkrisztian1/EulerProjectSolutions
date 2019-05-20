from shutil import copyfile, rmtree
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

def init_info(pr):
    with open(pr.pop('dir') + "/info.csv", "w", encoding="utf-8") as f:
        for key in pr.keys():
            f.write(f"{key}:{pr[key]}\n")
        
def init_problem(soup, i):
    pdir = root + "/" + "ID{:03}".format(i)
    make_dir(pdir)
    
    problem = {}
    problem['id']    = i
    problem['title'] = soup.find("h2").text
    problem['diff']  = soup.find("span").text.split(";")[-1][18:-1].strip()
    problem['dir']   = pdir
    problem['sol']   = None
    problem['state'] = 0
    
    init_info(problem)
    copyfile("templates/main.cpp", pdir+"/main.cpp")
    
    return problem


url = "https://projecteuler.net/recent"
page = requests.get(url)
soup = bs(page.content, 'html.parser')
numproblem = int(soup.find("td").text)

root = "../problems"
make_dir(root)

synclist = []

for i in range(1, numproblem + 1):
    pdir = root + "/" + "ID{:03}".format(i)
    
    if not os.path.isdir(pdir):
        synclist.append(i)
        
    elif not os.path.exists(pdir + "/main.cpp"):
        rmtree(pdir)
        synclist.append(i)
        
    elif not os.path.exists(pdir + "/info.csv"):
        rmtree(pdir)
        synclist.append(i)

Nsync = len(synclist)


for i in range(Nsync):
    
    url = f"https://projecteuler.net/problem={i+1}"
    page = requests.get(url)
    soup = bs(page.content, 'html.parser')
    problem = init_problem(soup, synclist[i])
    print(f"|{i+1:>3} / {Nsync} | {problem['id']:>3} | {problem['title']:.<50} | {problem['diff']:<3} | {(i+1) / Nsync * 100:.2f} %|\n")
    
    
print("All problems are up to date!")