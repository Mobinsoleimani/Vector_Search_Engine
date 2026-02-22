# Vector Search Engine 🚀

A fast and efficient Semantic Search Engine built using **Python** for text embedding and **C++** for high-performance vector similarity search.

## 📖 Overview
This project demonstrates how to combine the power of AI with the speed of C++. 
- **Python side:** Converts sentences into 384-dimensional vectors using the `all-MiniLM-L6-v2` model.
- **C++ side:** Reads the binary database and finds the best match using **Cosine Similarity** with $O(n)$ complexity.

## 🛠️ Project Structure
```text
.
├── cpp_engine/
│   ├── main.cpp          # Core C++ search logic
|
├── python_scripts/       # Scripts for embedding and data entry
└── README.md

```
How to Run
Requirements

    Python 3.x

    sentence-transformers library

    A C++ compiler (GCC/Clang)

Performance:

The search engine calculates the dot product and magnitude of vectors to determine the Confidence Score.
By using a binary format, we ensure fast I/O operations and low memory usage even as the database grows.
