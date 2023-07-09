DELIMITER $$

CREATE FUNCTION getNthHighestSalary(n INT) RETURNS INT

BEGIN
    DECLARE p INT;
    SET p = n - 1;
    RETURN (
        SELECT * FROM (
            SELECT
            DISTINCT salary
            FROM Employee
            ORDER BY salary DESC
            LIMIT 1 OFFSET p
    ) AS getNthHighestSalary);
END $$

DELIMITER ;


--------------------------------------------------------

探討:

這是第一次CREATE SQL FUNCTION ，要注意的是如果是直接在CONSOLE下指令
要先下 DELIMITER $$ 將結束符號改為 $$ ， 最後再下 DELIMITER ; 將結束符號改回;