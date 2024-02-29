#include <iostream>
#include <vector>

std::vector<std::vector<int>> mat_mul(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &b);
void mat_print(std::vector<std::vector<int>> m);

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Usage: main n\tn is the required index of the Fibonacci "
               "sequence\n");
        return 0;
    }

	int n = std::stoi(argv[1]);

	std::cout << "Fibonacci sequence @ " << n << ": ";

	if (n == 0) {
		std::cout << 0 << std::endl;
	} else if (n == 1) {
		std::cout << 1 << std::endl;
	} else {
		std::vector<std::vector<int>> magic_matrix = {{1, 1}, {1, 0}};
		std::vector<std::vector<int>> mat = {{1, 1}, {1, 0}};

		for (int i = 0; i < n - 2; i++) {
			 mat = mat_mul(magic_matrix, mat);
		}

		std::cout << mat[0][0] << std::endl;
	}

    return 0;
}

std::vector<std::vector<int>> mat_mul(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &b) {
	std::vector<std::vector<int>> res = {{0, 0}, {0, 0}};
	
	for (int i = 0; i < 2; i++) {			// Row in result matrix
		for (int j = 0; j < 2; j++) {		// Column in result matrix
			for (int k = 0; k < 2; k++) {   // Row/column in operands
				res[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	return res;
}

void mat_print(std::vector<std::vector<int>> m) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << "\n";
    }
}
