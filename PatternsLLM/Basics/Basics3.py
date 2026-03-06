def Calculator(num1: int, num2: int, operator: str) -> int | float:
    match operator:
        case '+':
            return num1 + num2
        case '-':
            return num1 - num2
        case '*':
            return num1 * num2
        case '/':
            return num1 / num2

def CheckChar(ans : str) -> bool:
    match ans:

        case 'a' | 'e' | 'i' | 'o' | 'u' | 'A' | 'E' | 'I' | 'O' | 'U':
            return True

        case _:
            return False


def Grade(marks : int) -> str:
    if marks >= 90:
        return 'A'
    elif marks >= 80:
        return 'B'
    elif marks >= 70:
        return 'C'
    else:
        return 'F'

print(f"{Calculator(1,2,'/')}")

print(f"{CheckChar('a')}")

print(f"{Grade(90)}")