# Write your MySQL query statement below
SELECT Person.lastname, Person.firstname, Address.city, Address.state FROM Person LEFT JOIN Address ON Person.personId = Address.personId;
