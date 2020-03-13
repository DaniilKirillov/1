
struct arr {
	size_t size;
	double* data;
	arr(int n) {
		this->size = n;
		this->data = new double[size];
	}
	~arr() {
		delete[] data;
	}
	arr(const arr& A) {
		if (this != &A) {
			this->size = A.size;
			this->data = new double[size];
			for (int i = 0; i < A.size; i++) {
				data[i] = A.data[i];
			}
		}
	}
	const arr& operator = (const arr & A){
		if (this ==& A) return *this;
		delete[]data;
		this->size = A.size;
		this->data = new double[size];
		for (int i = 0; i < size; i++) {
			data[i] = A.data[i];
		}
	}
	double& operator[] (int i) {
		if (i < 0 || i >= size) {
			cout << "err";
			return data[0];
		}
		return data[i];
	}
};