-----------------------------------------------------------------------
�ۤv�g��

SELECT
    IFNULL(null,u.unique_id) AS unique_id,
    e.name
FROM Employees AS e LEFT JOIN EmployeeUNI AS u ON e.id = u.id;

-----------------------------------------------------------------------
��������

SELECT b.unique_id, a.name 
FROM Employees AS a
LEFT JOIN EmployeeUNI AS b
ON a.id = b.id;

-----------------------------------------------------------------------

���Q:

�ۤv�h�g�F�@��IFNULL�禡�A���]���w�g��LEFT JOIN�F�A
���i�H�����g�A��SQL��²��