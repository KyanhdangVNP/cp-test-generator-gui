// Đây là code mẫu sinh phần input của test cho bài 2 (BAI2) trong kỳ thi Tin học trẻ tỉnh Phú Yên năm 2024-2025, bảng C2 (THPT không chuyên)
void inputGen(ofstream& inp) {
    int n = randNum(1, 5);
    inp << n << '\n';
    for (int i = 1; i <= n; i++) {
        inp << randNum(1, 5) << ' ' << randNum(1, 20) << '\n';
    }
}