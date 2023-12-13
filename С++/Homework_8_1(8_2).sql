DROP TABLE IF EXISTS flight_tasks, elements, positions;

CREATE TABLE flight_tasks(
	 flight_tasks_ID INT NOT NULL GENERATED ALWAYS AS IDENTITY PRIMARY KEY, -- идентификатор полетного задания (автоматически генерируемое значение, первичный ключ)
         launchX DOUBLE precision NOT NULL, -- X координата точки старта БР
         launchY DOUBLE precision NOT NULL, -- Y координата точки старта БР
         boomX DOUBLE precision NOT NULL, -- X координата точки падения БР
         boomY DOUBLE precision NOT NULL, -- Y координата точки падения БР
         t0 DOUBLE precision NOT NULL DEFAULT 0, -- время начала движения
         angle INT NOT NULL, -- угол бросания
         type INT NOT NULL DEFAULT 1 -- тип БР
);

CREATE TABLE elements(
         elements_ID INT NOT NULL GENERATED ALWAYS AS IDENTITY PRIMARY KEY, -- идентификатор элемента (автоматически генерируемое значение, первичный ключ)
         F_ID integer,
	 constraint F_IDR FOREIGN KEY (F_ID) REFERENCES flight_tasks(flight_tasks_ID), -- идентификатор полетного задания, из которого элемент был получен (внешний ключ на flight_tasks)
         launchX DOUBLE precision NOT NULL, -- X координата точки старта БР
         launchY DOUBLE precision NOT NULL, -- Y координата точки старта БР
         boomX DOUBLE precision NOT NULL, -- X координата точки падения БР
         boomY DOUBLE precision NOT NULL, -- Y координата точки падения БР
         tS DOUBLE precision NOT NULL DEFAULT 0, -- время начала движения
         tE DOUBLE precision NOT NULL -- время окончания движения
);

CREATE TABLE positions(
	 E_ID integer,
	 constraint E_IDR FOREIGN KEY (E_ID) REFERENCES elements (elements_ID), -- идентификатор элемента, для которого задаются опорные значения (внешний ключ на elements)
         time DOUBLE precision NOT NULL, -- момент времени, для которого получено значение
         x DOUBLE precision NOT NULL, -- X координата положения элемента в момент времени time
         y DOUBLE precision NOT NULL -- Y координата положения элемента в момент времени time
);

insert into flight_tasks(launchX,launchY,boomX,boomY,t0, angle) values(1,3.5,4,7,1,60);
insert into elements(launchX,launchY,boomX,boomY, tS, tE) values(1,3.5,4,7,1,5);
insert into positions(time, x, y) values(4, 3, 5.5);

SELECT * FROM flight_tasks;
SELECT * FROM elements;
SELECT * FROM positions;
