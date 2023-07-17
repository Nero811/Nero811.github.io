------------------------------
自己寫的:

SELECT
e.name,b.bonus
FROM Employee AS e LEFT JOIN Bonus AS b ON (e.empId = b.empId)
WHERE b.bonus IS null OR b.bonus < 1000;

------------------------------
網路答案:

SELECT a.name, b.bonus
FROM Employee AS a
LEFT JOIN Bonus AS b
ON a.empId = b.empId
WHERE a.empId NOT IN
(SELECT empId FROM Bonus WHERE bonus >= 1000);

------------------------------
探討:

本題重點是LEFT JOIN 的用法