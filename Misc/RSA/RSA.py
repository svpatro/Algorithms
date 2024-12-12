# Author: Shamik V. Patro
# Description: Since RSA encryption and decryption are similar operations, the RSA function is generic.

def RSA(text, binSplit, n):
    finalText = []
    for i in range(len(text)): # Until we run out of characters in the message
        base = text[i]
        letter = text[i] 
        print("Message Letter:", base)
        for j in range(3, len(binSplit)): # For all characters in the split string
            if (binSplit[j] == "1"):
                print("SM:", letter, "*", letter, "*", base, "=", end=" ")
                letter = ((letter ** 2) * base) % n
                print(letter, "mod", n)
            else:
                print("S:", letter, "*", letter, "=", end=" ")
                letter = (letter ** 2) % n
                print(letter, "mod", n)
        finalText.append(letter)
        print(" ")
    return finalText

def main():

    # Encrypting a message
    print("---------------")
    print("RSA Encryption:")
    print("---------------")
    encKey = 299
    n = 451
    plainText = [95, 222, 191]
    print("Original Message:", plainText)
    binKey = bin(encKey)
    binSplit = list(str(binKey)) 
    print("Encryption Key:", encKey, "=", binKey)
    print("First modular exponentiation operation is excluded due to redundancy.")
    print("")
    cipherMessage = RSA(plainText, binSplit, n)
    print("Cipher Message:", cipherMessage)
    print(" ")
    
    # Decrypting a message

    print("---------------")
    print("RSA Decryption:")
    print("---------------")
    decKey = 333
    n = 2668
    plainText = [141, 212, 95]
    print("Original Message:", plainText)
    binKey = bin(decKey)
    binSplit = list(str(binKey)) 
    print("Decryption Key:", decKey, "=", binKey)
    print("First modular exponentiation operation is excluded due to redundancy.")
    print("")
    plainMessage = RSA(plainText, binSplit, n)
    print("Plaintext Message:", plainMessage)
    print(" ")

main()