print("Helloo Python...!")

name : str = input("Enter your name: ")
age : int = int(input("Enter your age: "))
city : str = input("Enter your city: ")

print(f"Hello {name}, you are {age} years old and you live in {city}.")

n : int = int(input("Enter a number: "))


for i in range(1,n+1):
    for j in range(1,i+1):
        print("*", end=" ")
    print()