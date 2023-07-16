自己寫的
------------------------------
SELECT
a.name
FROM Employee AS a
INNER JOIN (
    SELECT
    managerId
    FROM Employee
    WHERE managerId IS NOT null
    GROUP BY managerId
    HAVING COUNT(managerId) >= 5
) AS b
ON a.id = b.managerId;

------------------------------

網路解答

子查詢
SELECT Name FROM Employee WHERE Id IN
(SELECT ManagerId FROM Employee
 GROUP BY ManagerId
 HAVING COUNT(*) >=5);

 關聯
 SELECT Name FROM Employee AS t1 JOIN
(SELECT ManagerId FROM Employee
 GROUP BY ManagerId
 HAVING COUNT(ManagerId) >= 5) AS t2
ON t1.Id = t2.ManagerId;
