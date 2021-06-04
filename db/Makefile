DBContainerName=mysql
MYSQL_USER=root
MYSQL_PASSWORD=root
MYSQL_DATABASE=playground

build:
	docker-compose build

up:
	docker-compose up

up/d:
	docker-compose up -d

up/b/d:
	docker-compose up --build -d

ps:
	docker-compose ps

down:
	docker-compose down

stop:
	docker stop  $(DBContainerName)

sql:
	docker exec -it $(DBContainerName) sh -c 'mysql -u $(MYSQL_USER) -p$(MYSQL_PASSWORD) $(MYSQL_DATABASE)'

sql/bash:
	docker exec -it $(DBContainerName) bin/bash