#include <iostream>
#include "absl/status/status.h"
#include "absl/status/statusor.h"

absl::Status Divide(int x, int y) {
    if (y == 0) {
        return absl::Status(absl::StatusCode::kInvalidArgument, "Division by zero");
    }
    return absl::OkStatus();
}

absl::StatusOr<int> DivideAndReturn(int x, int y) {
    absl::Status status = Divide(x, y);
    if (!status.ok()) {
        return status;
    } else {
        return x / y;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <x> <y>" << std::endl;
        return 1;
    }

    int x = std::stoi(argv[1]);
    int y = std::stoi(argv[2]);

    absl::StatusOr<int> result = DivideAndReturn(x, y);
    if (!result.ok()) {
        std::cerr << "Error: " << result.status().message() << std::endl;
        return 1;
    }
    std::cout << "Result: " << result.value() << std::endl;
    return 0;
}
