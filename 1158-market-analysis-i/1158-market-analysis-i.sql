# Write your MySQL query statement below
SELECT user_id AS buyer_id, join_date, COUNT(order_id) AS orders_in_2019 FROM Users
LEFT JOIN (
    SELECT * FROM Orders
    WHERE year(order_date) = "2019"
) o ON user_id = o.buyer_id
GROUP BY user_id