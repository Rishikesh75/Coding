i : int = int(input("Enter the integer"));

f : float = float(input("Enter the float"));

b : bool = bool(input("Enter the boolean"));

ch : str = input("Enter the char")[0];

s : str = input("Enter the string");

print(f"int:{i} float:{f} bool:{b} char:{ch} str:{s}");


def add(val1:int,val2:int) -> int:
    return val1+val2;

def sub(val1:int,val2:int)->int:
    return val1-val2;

def mul(val1:int,val2:int)->int:
    return val1*val2;

def div(val1:int,val2:int)->float:
    return val1 / val2;

def convertToFloat(val:int)->float:
    return float(val);


def swap(val1:int,val2:int):
    val1 = val1 - val2;
    val2 = val1+ val2;
    val1 = val2 - val1;
    return val1,val2;

def ASCIChar(ch:str):
    return ord(ch[0]);

def isEven(val:int) -> bool:
    if(val%2 ==0):
        return True;
    else:
        return False;

def largestNumber(num1 : int,num2 : int):
    if(num1>num2):
         return num1;
    else:
        return num2;

def largestNumber(num1 : int,num2 : int,num3 : int):
    if(num1>num2):
        if(num3>num1):
            return num2;
        else:
            return num1;
    else:
        if(num3>num2):
            return num3;
        else:
            return num2;


def findNumber(num1 : int) -> str:
    if(num1 > 0):
        return "pos";
    elif(num1 < 0):
        return "neg";
    else:
        return "Zero";


def leapYear(num1:int)-> int:
    if(num % 4 ==0):
        if(num % 100 == 0 and num % 400 !=0):
            return False;
        else:
            return True;
    else:
        return False;


def calculator(num1 : int,num2:int,char : str)->int:

    match char[0]:
        case '+':
            val = num1+num2
        case  '-':
            val = num1-num2

print(f"add:{add(1,2)} sub:{sub(1,2)} mul:{mul(1,2)} div:{div(1,2)}");

print(f"float:{convertToFloat(1)}");


print(f"Asci value of a is{ASCIChar('a')}");

print(f"isEven:{isEven(1)}")
val1,val2 = swap(1,2);

print(f"{largestNumber(1,2,3)}")

print(f"{findNumber(-1)}");