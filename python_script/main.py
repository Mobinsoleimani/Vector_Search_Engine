from sentence_transformers import SentenceTransformer
import numpy as np
model = SentenceTransformer('all-MiniLM-L6-v2', device="cpu")

def embedid_engine(text:str):
    embedding = model.encode(text,convert_to_numpy=True)
    return embedding.astype('float32')

user_input = input('add y0ur model')
embedding = embedid_engine(user_input)


print(embedding)
file = 'vector.bin'

with open(file,'ab') as b:
    b.write(embedding.tobytes())
    b.close()

with open("vector.txt",mode = 'w') as vector:
    vector.write(str(embedding))
    vector.close()