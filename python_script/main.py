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

data=input("add your input text: ")

embedding = embedid_engine(data)

user_input = input("add your input query: ")

embedding_query = embedid_engine(user_input)

file = 'mini_vector_search_engine/cpp_engine/vector.bin'

dim = embedding.shape[0]
num = 1
file_exists = os.path.isfile(file)
if not os.path.isfile(file):
    with open(file, "wb") as f:
        f.write(struct.pack("ii", 1, dim))
        f.write(embedding.tobytes())
else:
    with open(file, "r+b") as f:
        current_num = struct.unpack("i", f.read(4))[0]
        new_num = current_num + 1
        f.seek(0)
        f.write(struct.pack("i", new_num))
        f.seek(0, os.SEEK_END)
        f.write(embedding.tobytes())
with open("mini_vector_search_engine/cpp_engine/vector.txt", mode='a', encoding="utf-8") as vector:
    vector.write(data + "\n")

with open("mini_vector_search_engine/cpp_engine/query.bin",mode = 'wb') as query:
    query.write(embedding_query.tobytes())
    query.close()