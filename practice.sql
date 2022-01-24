CREATE TABLE Customer(CustomerID int PRIMARY KEY, CustomerName varchar(20) NOT NULL, Balance float, City varchar(20), Country varchar(20), ZipCode int);

INSERT INTO Customer VALUES(1, 'AtharvaCM', 5000.15, 'Pune', 'India', 411043);
INSERT INTO Customer VALUES(2, 'Rug', 4000.34, 'Pune', 'India', 411045);
INSERT INTO Customer VALUES(3, 'Swup', 6000, 'Mumbai', 'India', 411009);
INSERT INTO Customer VALUES(4, 'John', 5500, 'New York', 'USA', 10005);
INSERT INTO Customer VALUES(5, 'Jordan', 3470, 'LA', 'USA', 10003);
INSERT INTO Customer VALUES(6, 'Usha', 6985.57, 'Berlin', 'Germany', 10013);

CREATE TABLE OrderTable(OrderID int PRIMARY KEY, CustomerID int REFERENCES Customer(CustomerID) ON DELETE CASCADE ON UPDATE CASCADE, OrderDate date);

INSERT INTO OrderTable VALUES(1001, 1, '2020-04-24');
INSERT INTO OrderTable VALUES(1002, 2, '2020-04-24');
INSERT INTO OrderTable VALUES(1003, 1, '2020-04-24');
INSERT INTO OrderTable VALUES(1004, 7, '2020-04-24');

-- SELECT * FROM OrderTable;

-- SELECT * FROM Customer;

-- WHERE clause 
-- SELECT * FROM Customer WHERE Country='USA';

-- AND 
-- SELECT * FROM Customer WHERE Country='USA' AND City='LA';

-- OR
-- SELECT * FROM Customer WHERE City='LA' OR City='Pune';

-- NOT
-- SELECT * FROM Customer WHERE NOT City='Pune';

-- AND OR NOT
-- SELECT * FROM Customer WHERE Country='India' AND (NOT City='Mumbai' OR City='Pune');

-- UPDATE
-- UPDATE Customer SET CustomerName='Rugvedi' WHERE CustomerID=2;
-- SELECT * FROM Customer;

-- DELETE
-- DELETE FROM Customer WHERE CustomerName='Usha';

-- Aggregate functions

-- COUNT()
-- SELECT COUNT(Country) FROM Customer WHERE Country='India';
-- SELECT COUNT(Country) FROM Customer WHERE Country='India' AND City='Pune';

-- AVG()
-- SELECT AVG(Balance) FROM Customer WHERE CustomerID < 4;

-- SUM()
-- SELECT SUM(Balance) FROM Customer WHERE CustomerID < 5;

-- MAX()
-- SELECT MAX(Balance) FROM Customer;

-- MIN()
-- SELECT MIN(Balance) FROM Customer;

-- SQL JOINS
-- SELECT OrderTable.OrderID, Customer.CustomerName, OrderTable.OrderDate FROM OrderTable INNER JOIN Customer ON OrderTable.CustomerID = Customer.CustomerID;

-- ORDER BY
-- SELECT CustomerID, CustomerName, Country FROM Customer ORDER BY Country, CustomerName;

-- GROUP BY
-- SELECT COUNT(CustomerID), Country FROM Customer GROUP BY Country ORDER BY CustomerName;

-- ALTER TABLE
-- ALTER TABLE OrderTable ADD OrderStatus int CHECK(OrderStatus in (1, 0));
-- UPDATE OrderTable SET OrderStatus=0;
