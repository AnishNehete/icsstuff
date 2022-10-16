import sys
import hashlib

if sys.version_info < (3, 6):
	import sha3

file = open('input.txt', 'r')

print("\nSHA3-512 Hash: \n")

for text in file:
    hash_sha3_512 = hashlib.new('sha3_512', text.encode())
    print(hash_sha3_512.hexdigest())