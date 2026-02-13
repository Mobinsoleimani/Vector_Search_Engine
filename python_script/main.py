from sentence_transformers import SentenceTransformer
import numpy as np
import struct
import os
model = SentenceTransformer('all-MiniLM-L6-v2', device="cpu")

def embedid_engine(text:str):
    vec = model.encode(
        text,
        convert_to_numpy=True,
        normalize_embeddings=True
    )
    return vec.astype(np.float32)

user_input=input("add your input text: ")

embedding = embedid_engine(user_input)

file = 'vector.bin'

dim = embedding.shape[0]
num = 1
file_exists = os.path.isfile(file)
with open(file, "ab") as f:
    f.write(struct.pack("ii", num, dim))
    f.write(embedding.tobytes())
with open("vector.txt",mode = 'a',encoding="utf-8") as vector:
    vector.write(user_input)
    vector.close()