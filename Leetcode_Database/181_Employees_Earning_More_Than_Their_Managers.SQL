--------------------------------
自己寫的:

SELECT
a.name AS Employee 
FROM Employee AS a INNER JOIN (
SELECT id,salary FROM Employee) AS b
WHERE a.managerID = b.id AND a.salary > b.salary;

--------------------------------
網路解答:

1.
SELECT a.Name AS 'Employee' FROM Employee AS a
JOIN Employee AS b
ON a.ManagerId = b.Id
WHERE a.Salary > b.Salary;

2.
SELECT a.Name AS 'Employee'
FROM Employee AS a, Employee AS b
WHERE a.ManagerId = b.Id
AND a.Salary > b.Salary;


--------------------------------

