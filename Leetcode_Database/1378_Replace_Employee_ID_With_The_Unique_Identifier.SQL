-----------------------------------------------------------------------
自己寫的

SELECT
    IFNULL(null,u.unique_id) AS unique_id,
    e.name
FROM Employees AS e LEFT JOIN EmployeeUNI AS u ON e.id = u.id;

-----------------------------------------------------------------------
網路答案

SELECT b.unique_id, a.name 
FROM Employees AS a
LEFT JOIN EmployeeUNI AS b
ON a.id = b.id;

-----------------------------------------------------------------------

探討:

自己多寫了一個IFNULL函式，但因為已經用LEFT JOIN了，
其實可以不必寫，讓SQL更簡潔