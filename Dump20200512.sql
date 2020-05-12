CREATE DATABASE  IF NOT EXISTS `baz_mail` /*!40100 DEFAULT CHARACTER SET utf8 */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `baz_mail`;
-- MySQL dump 10.13  Distrib 8.0.20, for Win64 (x86_64)
--
-- Host: localhost    Database: baz_mail
-- ------------------------------------------------------
-- Server version	8.0.20

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `directory`
--

DROP TABLE IF EXISTS `directory`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `directory` (
  `id_directory` int unsigned NOT NULL AUTO_INCREMENT,
  `directory_name` varchar(45) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT NULL,
  `directory_mail` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT NULL,
  PRIMARY KEY (`id_directory`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `directory`
--

LOCK TABLES `directory` WRITE;
/*!40000 ALTER TABLE `directory` DISABLE KEYS */;
INSERT INTO `directory` VALUES (1,'1 Направление 5 отдела СОКР','1napr5otduk@citrin.ru'),(2,'2 Направление 5 отдела СОКР','2napr5otduk@citrin.ru'),(3,'3 Направление 5 отдела СОКР','3napr5otduk@citrin.ru'),(4,'Информационно-аналитическая группа','iag5otduk@citrin.ru');
/*!40000 ALTER TABLE `directory` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Temporary view structure for view `directory_view`
--

DROP TABLE IF EXISTS `directory_view`;
/*!50001 DROP VIEW IF EXISTS `directory_view`*/;
SET @saved_cs_client     = @@character_set_client;
/*!50503 SET character_set_client = utf8mb4 */;
/*!50001 CREATE VIEW `directory_view` AS SELECT 
 1 AS `dir_name`,
 1 AS `dir_mail`*/;
SET character_set_client = @saved_cs_client;

--
-- Table structure for table `received_mail`
--

DROP TABLE IF EXISTS `received_mail`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `received_mail` (
  `idreceived_mail` int NOT NULL AUTO_INCREMENT,
  `received_mail_date` date NOT NULL,
  `received_mail_sender` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT NULL,
  `received_mail_inf` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT NULL,
  `received_file_url` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT NULL,
  PRIMARY KEY (`idreceived_mail`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `received_mail`
--

LOCK TABLES `received_mail` WRITE;
/*!40000 ALTER TABLE `received_mail` DISABLE KEYS */;
INSERT INTO `received_mail` VALUES (3,'2000-01-01','1','info','not file'),(4,'2000-01-01','3','01','01'),(5,'2000-03-03','2','03','03'),(6,'2000-03-03','1','03','03'),(7,'2000-03-04','2','04','03');
/*!40000 ALTER TABLE `received_mail` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Temporary view structure for view `received_view`
--

DROP TABLE IF EXISTS `received_view`;
/*!50001 DROP VIEW IF EXISTS `received_view`*/;
SET @saved_cs_client     = @@character_set_client;
/*!50503 SET character_set_client = utf8mb4 */;
/*!50001 CREATE VIEW `received_view` AS SELECT 
 1 AS `received_mail_date`,
 1 AS `received_mail_sender`,
 1 AS `received_mail_inf`,
 1 AS `received_file_url`*/;
SET character_set_client = @saved_cs_client;

--
-- Table structure for table `send_mail`
--

DROP TABLE IF EXISTS `send_mail`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `send_mail` (
  `idsend_mail` int NOT NULL AUTO_INCREMENT,
  `send_mail_date` date NOT NULL,
  `send_mail_recipient` int unsigned NOT NULL,
  `send_mail_inf` varchar(30) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT NULL,
  `send_file_url` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci DEFAULT NULL,
  PRIMARY KEY (`idsend_mail`),
  KEY `FK_send_mail_directory` (`send_mail_recipient`),
  CONSTRAINT `FK_send_mail_directory` FOREIGN KEY (`send_mail_recipient`) REFERENCES `directory` (`id_directory`)
) ENGINE=InnoDB AUTO_INCREMENT=25 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `send_mail`
--

LOCK TABLES `send_mail` WRITE;
/*!40000 ALTER TABLE `send_mail` DISABLE KEYS */;
INSERT INTO `send_mail` VALUES (12,'2000-01-01',2,'info','not file'),(13,'2000-01-02',1,'info','not file'),(14,'2000-01-02',3,'info','not file'),(15,'2000-01-03',1,'info','nf'),(16,'2000-01-03',1,'test','no file'),(17,'2000-02-05',1,'info','not file'),(18,'2000-01-05',2,'info','not file'),(19,'2000-01-01',1,'info','not file'),(20,'2000-01-06',1,'06','01'),(21,'2000-01-06',2,'06','01'),(22,'2000-01-05',1,'ftp','ftp'),(23,'2000-02-02',3,'02','02'),(24,'2000-03-01',1,'01','03');
/*!40000 ALTER TABLE `send_mail` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Temporary view structure for view `send_view`
--

DROP TABLE IF EXISTS `send_view`;
/*!50001 DROP VIEW IF EXISTS `send_view`*/;
SET @saved_cs_client     = @@character_set_client;
/*!50503 SET character_set_client = utf8mb4 */;
/*!50001 CREATE VIEW `send_view` AS SELECT 
 1 AS `send_mail_date`,
 1 AS `send_mail_recipient`,
 1 AS `send_mail_inf`,
 1 AS `send_file_url`*/;
SET character_set_client = @saved_cs_client;

--
-- Final view structure for view `directory_view`
--

/*!50001 DROP VIEW IF EXISTS `directory_view`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8mb4 */;
/*!50001 SET character_set_results     = utf8mb4 */;
/*!50001 SET collation_connection      = utf8mb4_0900_ai_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `directory_view` (`dir_name`,`dir_mail`) AS select `directory`.`directory_name` AS `directory_name`,`directory`.`directory_mail` AS `directory_mail` from `directory` */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;

--
-- Final view structure for view `received_view`
--

/*!50001 DROP VIEW IF EXISTS `received_view`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8mb4 */;
/*!50001 SET character_set_results     = utf8mb4 */;
/*!50001 SET collation_connection      = utf8mb4_0900_ai_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `received_view` AS select `received_mail`.`received_mail_date` AS `received_mail_date`,`received_mail`.`received_mail_sender` AS `received_mail_sender`,`received_mail`.`received_mail_inf` AS `received_mail_inf`,`received_mail`.`received_file_url` AS `received_file_url` from `received_mail` */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;

--
-- Final view structure for view `send_view`
--

/*!50001 DROP VIEW IF EXISTS `send_view`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8mb4 */;
/*!50001 SET character_set_results     = utf8mb4 */;
/*!50001 SET collation_connection      = utf8mb4_0900_ai_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `send_view` AS select `send_mail`.`send_mail_date` AS `send_mail_date`,`send_mail`.`send_mail_recipient` AS `send_mail_recipient`,`send_mail`.`send_mail_inf` AS `send_mail_inf`,`send_mail`.`send_file_url` AS `send_file_url` from `send_mail` */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-05-12 19:38:55
