import rsa

# Implementing helper methods to generate private and public keys
def generateKeys():
    (publicKey, privateKey) = rsa.newkeys(1024)
    with open('keys/publicKey.pem', 'wb') as p:
        p.write(publicKey.save_pkcs1('PEM'))
    with open('keys/privateKey.pem', 'wb') as p:
        p.write(privateKey.save_pkcs1('PEM'))

# Implementing method to load the keys
def loadKeys():
    with open('keys/publicKey.pem', 'rb') as p:
        publicKey = rsa.PublicKey.load_pkcs1(p.read())
    with open('keys/privateKey.pem', 'rb') as p:
        privateKey = rsa.PrivateKey.load_pkcs1(p.read())
    return privateKey, publicKey

# Implementing the encryption method
def encrypt(message, key):
    return rsa.encrypt(message.encode('ascii'), key)

# Implementing the decryption method
def decrypt(ciphertext, key):
    try:
        return rsa.decrypt(ciphertext, key).decode('ascii')
    except:
        return False

def sign(message, key):
    return rsa.sign(message.encode('ascii'), key, 'SHA-1')

def verify(message, signature, key):
    try:
        return rsa.verify(message.encode('ascii'), signature, key) == 'SHA-1'
    except:
        return False

generateKeys()
privateKey, publicKey = loadKeys()

message = input('Write your message here: ')
ciphertext = encrypt(message, publicKey)

signature = sign(message, privateKey)

text = decrypt(ciphertext, privateKey)

print('\n')

print(f'Cipher Text: {ciphertext}')
print('\n')
print(f'Text: {text}')