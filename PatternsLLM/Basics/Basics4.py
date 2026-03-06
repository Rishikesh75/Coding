n:int = int(input("Enter a number: "))

for i in range(n):
    print(f"{i}",end=" ")

print("\n")

for i in range(n,0,-1):
    print(f"{i}",end=" ")

print("\n")

sum : int = 0
for i in range(0,n+1):
    sum += i
print(f"Sum:{sum}")

for i in range(1,11):
    print(f"{n} * {i} = {n*i}",end="\n")

fac : int = 1
for i in range(1,n+1):
    fac *= i

print(f"Factorial:{fac}")

def reversed_number(num:int)->int:
    reversedNumber : int = 0
    while num > 0:
         rem:int = num % 10
         num = int(num / 10)
         reversedNumber  = reversedNumber * 10 + rem

    return reversedNumber

print(f"ReversedNumber:{reversed_number(n)}")


def check_palimdrome(num:int)->bool:
    val : int = reversed_number(num)
    if(val == num):
        return True
    else:
        return False

def count_digits(num:int)->(int,int):
    count : int = 0
    sum : int =0;
    while num > 0:
        count += 1
        rem : int = num % 10
        num /= 10
        sum += rem

    return count,sum

def prime_number(num : int)->bool:

    count : int = 0

    for i in range(2,num):
        if num % i == 0:
            count += 1

    if count > 0:
        return False
    else:
        return True
