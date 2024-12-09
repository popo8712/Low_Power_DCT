import numpy as np

def generate_test_data(size=8):
    np.random.seed(0)
    data = np.random.randint(0, 256, (size, size))
    print("Generated Test Data:")
    print(data)
    return data

if __name__ == "__main__":
    generate_test_data()
