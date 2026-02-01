from sentence_transformers import SentenceTransformer

model = SentenceTransformer('all-MiniLM-L6-v2', device="cpu")

def embedid_engine(text:str):
    embedding = model.encode(text)
    return embedding


x = embedid_engine(str(input('add y0ur model')))


print(x)
with open("vector.txt",mode = 'w') as vector:
    vector.write(str(x))
    vector.close()