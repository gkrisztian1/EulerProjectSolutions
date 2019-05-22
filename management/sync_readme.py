import os

def load_info(loc):
    with open(loc, "w") as f:
        raw = f.read()

root = "../problems"

dirs = os.listdir(root)

df = {
      'id': [],
      'title': [],
      'diff': [],
      'sol': [],
      'state':[]
      }


for dr in dirs:
    print(dr)