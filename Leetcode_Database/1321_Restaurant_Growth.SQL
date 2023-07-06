SELECT visited_on,amount,average_amount FROM(
SELECT
    visited_on,
    ROW_NUMBER() OVER(ORDER BY visited_on) AS RowNumber,
    SUM(SUM(amount)) OVER(ORDER BY visited_on ROWS 6 PRECEDING) AS amount,
    ROUND(SUM(SUM(amount)) OVER(ORDER BY visited_on ROWS 6 PRECEDING)/7,2) AS average_amount
FROM Customer
GROUP BY visited_on) AS TEMP
WHERE RowNumber >= 7;


--���I:
--1.OVER(ORDER BY visited_on ROWS 6 PRECEDING) �֥[�C6�����ƾ�
--2.SUM(SUM(amount)) �p�⭫�ƤѼ�
--3.ROW_NUMBER() OVER(ORDER BY visited_on) AS RowNumber �p���ƥΩ�WHERE RowNumber >= 7 ��^�j��7�Ѫ�����