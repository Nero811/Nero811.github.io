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

���Q:

�o�O�Ĥ@��CREATE SQL FUNCTION �A�n�`�N���O�p�G�O�����bCONSOLE�U���O
�n���U DELIMITER $$ �N�����Ÿ��אּ $$ �A �̫�A�U DELIMITER ; �N�����Ÿ���^;