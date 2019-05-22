
def format_num(num, c):
    s1 = f'<span style="color:{c}">**{num}**</span>'
    s2 = f"[{s1}](../problems/ID{num:03})"
    
    return s2

w = 25

done = [1,44, 23, 23]


r = 10
c = 10

assert r * c >= w, f"{r} * {c} = {r * c}  < {w} !"

for i in range(r):
    if i == 1:
        print("|-"*c)
    for j in range(c):
        num = c * i + j + 1
        if num <= w:
            if num in done:
                print(f"| {format_num(num, 'green')}", end='')
            else:
                print(f"| {format_num(num, 'black')}", end='')
        
    print()