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
    }
    return x / y;
}

int main() {
    absl::StatusOr<int> result = DivideAndReturn(10, 0);
    if (!result.ok()) {
        std::cerr << "Error: " << result.status().message() << std::endl;
        return 1;
    }
    std::cout << "Result: " << result.value() << std::endl;
    return 0;
}
