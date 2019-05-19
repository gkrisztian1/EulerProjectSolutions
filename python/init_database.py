import requests
import pandas as pd
from bs4 import BeautifulSoup as bs


df = {
      "ID" : [],
      "Title": [],
      "Difficulty": [],
      "State": [],
      "Solution": []
      }

for i in range(1, 670):
    site = f"https://projecteuler.net/problem={i}"
    
    page = requests.get(site)
    
    if page.status_code != 200:
        raise ValueError("Something went wrong!")
        
        
    soup = bs(page.content, 'html.parser')
    problem_title = soup.findAll("h2")[0].get_text()
    
    problem_difficulty = soup.findAll("span")[0].get_text().split(";")[-1][18:-1]
    
    df["ID"].append(i)
    df["Title"].append(problem_title)
    df["Difficulty"].append(problem_difficulty)
    df["State"].append("intact")
    df["Solution"].append(0)
    print(f"{i} | {problem_title} | {problem_difficulty}")


df = pd.DataFrame(df)
df.to_csv("database.csv", sep=",", index=False)