***PLEASE READ FORE GRADING***
I was unable to complete all of the methods needed. 
I could not figure out how to complete addLikeGroup.
I also could not figure out how to implement triggers or how to do stored procedure.
Even though it is not implemeted I have the SQL completed for q3 below:

CREATE PROCEDURE add_artwork (
    IN title VARCHAR(100),
    IN year INTEGER,
    IN type VARCHAR(100),
    IN price DOUBLE PRECISION,
    IN a_name VARCHAR(100),
    IN g_name VARCHAR(100)
)
BEGIN
    INSERT INTO artwork (title, year, type, price, a_name)
    VALUES (title, year, type, price, a_name);

    IF NOT EXISTS (SELECT * FROM a_group WHERE g_name = g_name) THEN
        INSERT INTO a_group (g_name) VALUES (g_name);
    END IF;

    INSERT INTO classify (title, g_name) VALUES (title, g_name);
END;

