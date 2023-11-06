class SeatManager {
    priority_queue<int, vector<int>, greater<int>> availableSeats;

public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {
            availableSeats.push(i);
        }
    }

    int reserve() {
        int seatNumber = availableSeats.top();
        availableSeats.pop();
        return seatNumber;
    }

    void unreserve(int seatNumber) {
        availableSeats.push(seatNumber);
    }
};