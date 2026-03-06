n : int = int(input("Enter the Number"))

for i in range(1,n+1):
    for j in range(1,i+1):
        print(f"*",end="")
    print(end="\n")

print(end="\n")

for i in range(n,0,-1):
    for j in range(0,i):
        print(f"*",end="")
    print(end="\n")
