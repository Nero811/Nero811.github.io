-------------------------------------------
自己寫的:

SELECT
d.name AS Department,
e.Employee AS Employee,
e.Salary AS Salary
FROM Department AS d INNER JOIN(
    SELECT
    a.name AS Employee,
    a.salary AS Salary,
    a.departmentId AS id
    FROM Employee AS a INNER JOIN(
        SELECT
        MAX(salary) AS salary,departmentId
        FROM Employee
        GROUP BY departmentId) AS b
ON a.salary = b.salary AND a.departmentId = b.departmentId) AS e
ON e.id = d.id;

-------------------------------------------

網路解答:
1. 兩層INNER JOIN
SELECT b.Name AS Department, a.Name AS Employee, a.Salary AS 'Salary' FROM Employee AS a
INNER JOIN Department AS b
ON a.DepartmentId = b.Id
INNER JOIN
(SELECT  DepartmentId, MAX(Salary) AS Salary FROM Employee
 GROUP BY DepartmentId) AS c
ON a.DepartmentId = c.DepartmentId
WHERE a.Salary = c.Salary;


2. 關聯子查詢
SELECT b.Name AS Department, a.Name AS Employee, a.Salary AS 'Salary' FROM Employee AS a
INNER JOIN Department AS b
ON a.DepartmentId = b.Id
WHERE a.Salary IN
 (SELECT MAX(Salary) FROM Employee AS c
  WHERE a.DepartmentId = c.DepartmentId
  GROUP BY c.DepartmentId);
