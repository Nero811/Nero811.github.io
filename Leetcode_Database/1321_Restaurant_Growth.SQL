SELECT visited_on,amount,average_amount FROM(
SELECT
    visited_on,
    ROW_NUMBER() OVER(ORDER BY visited_on) AS RowNumber,
    SUM(SUM(amount)) OVER(ORDER BY visited_on ROWS 6 PRECEDING) AS amount,
    ROUND(SUM(SUM(amount)) OVER(ORDER BY visited_on ROWS 6 PRECEDING)/7,2) AS average_amount
FROM Customer
GROUP BY visited_on) AS TEMP
WHERE RowNumber >= 7;


--重點:
--1.OVER(ORDER BY visited_on ROWS 6 PRECEDING) 累加每6筆錢數據
--2.SUM(SUM(amount)) 計算重複天數
--3.ROW_NUMBER() OVER(ORDER BY visited_on) AS RowNumber 計算行數用於WHERE RowNumber >= 7 返回大於7天的筆數