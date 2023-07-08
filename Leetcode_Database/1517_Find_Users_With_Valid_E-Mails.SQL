------------------------------
自己寫的 

(第一次 錯誤)
SELECT
user_id,name,mail
FROM Users
WHERE (SUBSTRING_INDEX(mail,"@",-1) = "leetcode.com") AND (
SUBSTRING_INDEX(mail,"@",1) REGEXP '^[A-Z][A-Z0-9_.-]*$');

(第二次 正確)
SELECT * FROM Users
WHERE (SUBSTRING_INDEX(mail,"@",-1) = "leetcode.com") AND 
mail REGEXP '^[A-Z][A-Z0-9_.-]*@leetcode.com$';

------------------------------

網路解答 (錯的)

SELECT * FROM Users
WHERE mail REGEXP '^[A-Z][A-Z0-9_.-]*@leetcode.com$';


------------------------------


探討:
此題要使用正規表達式解題，
自己第一次用SUBSTRING_INDEX拆分字串，但是測試資料有可能會有兩個@，導致SUBSTRING_INDEX(mail,"@",1)會SELECT多的資料 如: Naftali@JQQPcQcHLG@leetcode.com，
後來參考網路解法，也是錯的，因為只有判斷com結尾，資料也有可能是@leetcode?com結尾。

本題還有個重點是*的用法，需要用*才會不斷去比對字串。


