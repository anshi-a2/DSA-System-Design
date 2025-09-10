# Designing a Metrics Monitoring and Alerting System


---

## Introduction

Designing a metrics monitoring and alerting system is a crucial step in ensuring the health and performance of any system or application. A well-designed system can help identify potential issues before they become critical, allowing for quick resolution and minimizing downtime.

The first step in designing a metrics monitoring and alerting system is to identify the key metrics that need to be monitored. These metrics should be chosen based on the specific goals and objectives of the system or application, as well as its unique characteristics and requirements. For example, a website may need to monitor metrics such as page load time, user engagement, and server response time, while a mobile app may need to monitor metrics such as battery usage and network performance.

Once the key metrics have been identified, the next step is to determine how they will be collected and stored. This may involve setting up specialized monitoring tools or using existing tools and services. It is important to ensure that the data collected is accurate, reliable, and easily accessible.

The next step is to set up alerts and notifications based on the metrics being monitored. This can be done using a variety of tools and methods, such as email, SMS, or push notifications. The alert thresholds should be carefully chosen to ensure that they are sensitive enough to detect potential issues, but not so sensitive that they generate erroneous alerts.

Finally, it is important to regularly review and assess the performance of the metrics monitoring and alerting system. This can involve analyzing the data collected, identifying areas for improvement, and making any necessary adjustments to the system. By continuously improving the system, it can remain effective and reliable over time.




---

##  Major Components of the System

The monitoring and alerting system consists of five key components:

1. **Data Collection**: Gathers metric data from various resources (e.g., application servers, databases, message queues).
2. **Data Transmission**: Transfers collected metrics to the monitoring system.
3. **Data Storage**: Organizes and stores incoming time-series data.
4. **Alerting**: Analyzes metrics, detects anomalies, and sends alerts to configured communication channels.
5. **Visualization**: Displays data via charts, graphs, and dashboards for easier trend analysis and issue detection.

---

##  High-Level Architecture

**System Flow:**

<img width="1283" height="456" alt="image" src="https://github.com/user-attachments/assets/23f3599b-ce13-4c82-8e5b-a97fb49f8b1a" />


- **Metrics Source**: Applications, databases, queues, etc.
- **Metrics Collector**: Aggregates and forwards metrics to the TSDB.
- **Time-Series Database**: Stores metrics, provides optimized query access via labels.
- **Query Service**: Fetches data from the TSDB for use by both visualization and alerting components.
- **Visualization System**: Generates dashboards and charts.
- **Alerting System**: Triggers notifications via various channels.

---

# Design Deep Dive

Let's investigate the designs in detail:

- Metrics collection
- Scaling the metrics transmission pipeline
- Query service
- Alerting system
- Visualization system

---

## Metrics Collection

There are two ways metrics data can be collected – **pull** or **push**.

<img width="1283" height="456" alt="image" src="https://github.com/user-attachments/assets/5ea29c13-aa20-44b3-a02e-7674b805a282" />


### Pull Model

In a pull model, the metrics collector pulls the metrics from the sources. Consequently the metrics collector needs to know the complete list of service ends to pull the data. We can use a reliable, scalable and maintainable service like service discovery, provided by ETCD and Zookeeper. A service discovery contains configuration rules about when and where to collect the metrics.

- The metrics collector fetches the configuration metadata of service endpoint from service discovery. Metadata includes pulling interval, IP addresses, timeout and retry parameters.
- The metrics collector pulls the metric data using the HTTP endpoint (for example, web servers) or TCP (transmission control protocol) endpoint (for DB clusters).
- The metrics collector registers a change event notification with the service directory to get an update whenever the service endpoints change.

<img width="1283" height="404" alt="image" src="https://github.com/user-attachments/assets/92aa905c-abbd-4961-856b-05f32297c7f1" />


### Push Model

In a push model, a collection agent is installed on every server that is being monitored. A collection agent is long-running software that collects the metrics from the service running on the server and pushes those metrics to the collector.

To prevent the metrics collector from falling behind a push model, the collector should always be in an autoscaling position with a load balancer in the front of it (**Figure 4**). The cluster should scale up or down based on the CPU (central processing unit) load of the metrics collector.

<img width="1283" height="404" alt="image" src="https://github.com/user-attachments/assets/e080c66f-79bb-4bb8-83be-ae1ab55db0c1" />


### Pull or Push?

So, what's best for a large organization? Knowing the advantages and disadvantages of each approach is important. A large organization needs to support both, especially serverless architecture.

#### Push Monitoring System

**Advantages:**

- Real-time notifications of issues and alerts
- Can alert multiple recipients at once
- Can be customized to specific needs and requirements
- Can be integrated with other systems and applications

**Disadvantages:**

- Requires a constant and reliable internet connection to function properly
- Can be overwhelming with too many notifications and alerts
- Can be vulnerable to cyber-attacks and security breaches

#### Pull Monitoring System

**Advantages:**

- Can be accessed remotely and for multiple devices
- Can be set up to check specific metrics and parameters at regular intervals
- Can be easily configured and customized
- Can provide detailed and historical data for analysis and reporting

**Disadvantages:**

- Requires manual intervention to check and review the data
- May not provide real-time alerts and notifications
- Can be less efficient in identifying and responding to issues and anomalies

---

## Scaling the Metrics Transmission Pipeline

Whether we use the push or pull model, the metrics collector of servers and the cluster receive enormous amounts of data. There's a risk of data loss if the time-series database is unavailable. To navigate through the risk of losing data, we can use a queueing component as shown below.

<img width="1283" height="404" alt="image" src="https://github.com/user-attachments/assets/b28f8836-3fbc-4a04-966d-d57ffdf91734" />


- In this design, the metrics collector sends metric data to a queuing system like Kafka.
- Consumers or streaming processing services such as Apache Spark process and push the data to the time-series database.
- Advantages:
  - Kafka is used as a highly reliable and scalable distributed messaging platform.
  - It decouples the data collection and processing services from one another.
  - It can easily prevent data loss when the database is unavailable by retaining the data in Kafka.


---

## Query Service

The query service comprises a cluster of query servers which access the time-series database and handle the requests from the visualization or alerting systems. Once you have a dedicated set of query servers, you can decouple time-series database from the visualization and alerting systems. This provides flexibility to change the time-series database or visualization/alerting systems whenever needed.

To reduce the load of the time-series database and make the query service more performant, cache servers can be added to store query results, as shown in **Figure 6**.

<img width="1283" height="404" alt="image" src="https://github.com/user-attachments/assets/87e8eeb3-5b24-4e8d-9286-009264de96de" />


### Storage Layer

**Space Optimization Strategies:**

- **Data encoding and compression**: Translate data into more efficient formats and compress it to reduce storage size.
- **Downsampling**: Reduce the number of samples in a dataset by removing some data points.  
  Example retention strategy:
  - 7 days: no sampling
  - 30 days: downsample to 1-minute resolution
  - 1 year: downsample to 1-hour resolution

---

## Alerting System

A monitoring system allows administrators to define situations to be actively managed while relying on passive software monitoring.

**Alert Flow:**

1. Load config files to cache servers (rules defined as config files on disk).
<img width="1283" height="404" alt="image" src="https://github.com/user-attachments/assets/dbdefd8e-1c01-4420-8b73-528536bf12f6" />

3. Alert manager fetches alert configs from the cache.
4. Based on config rules, the alert manager calls the query service at a predefined interval. If the value violates the threshold, an alert event is created.
5. Alert manager responsibilities:
   - Filter, merge, and deduplicate alerts
  
     <img width="1283" height="472" alt="image" src="https://github.com/user-attachments/assets/2b01fe83-ee06-4a90-8851-4daefc2e3df3" />

   - Access control to restrict operations to authorized users
   - Retry notifications to ensure alerts are sent at least once
6. Alert store: key-value database (e.g., Cassandra) keeps alert state (inactive, pending, firing, resolved)
7. Eligible alerts are inserted into a messaging system like Kafka
8. Alert consumers pull alert events and send notifications to channels such as email, SMS, PagerDuty, or HTTP endpoints

**Figure 7: Alerting system**  
**Figure 8: Merge alerts**

---

## Visualization System

Visualization is built on top of the data layer. Metrics can be shown on dashboards over various time scales and alerts can be displayed as well. Building a high-quality visualization system is challenging; there is a strong argument for using an off-the-shelf system.  
**Example:** Grafana can be used for this purpose.

---

# Low Level Design 

## Monitoring and Alerting Architecture

### 1. Codebase / Application

- Exposes metrics via client libraries → `/metrics` endpoint.

**Example metric:**

`http_requests_total{service="auth", status="500"} 42`

---

## 2. Prometheus

- Scrapes metrics from the app.
- Stores them in TSDB.
- PromQL queries can be used both for:
  - Dashboards (Grafana)
  - Alert evaluation (Alertmanager integration)

---

## 3. Alerting in Prometheus

You define alerting rules in Prometheus config.

**Example:**

```yaml
groups:
  - name: service-rules
    rules:
      - alert: HighErrorRate
        expr: rate(http_requests_total{service="auth",status=~"5.."}[5m]) 
              / rate(http_requests_total{service="auth"}[5m]) > 0.05
        for: 2m
        labels:
          severity: critical
        annotations:
          summary: "Auth service has >5% error rate"

```

Prometheus evaluates these rules periodically (every 15s by default).

If a rule triggers → Prometheus sends alert events to Alertmanager.

## 4. Alertmanager

Responsibilities:

Deduplication (avoid duplicate alerts)

Grouping (batch alerts, e.g., by service/region)

Routing (decide who gets notified)

Silencing & inhibition (prevent alert storms, suppress less important alerts)

Notifications sent to external channels:

Slack, PagerDuty, Email, SMS, Webhooks

## 5. Grafana

Queries Prometheus for visualization (PromQL)

Can also define alerts inside Grafana panels:

Grafana → Prometheus query → compare against threshold → fire alert

Grafana can send to its own notification channels (Slack, Teams, etc.)

In production setups: Prometheus + Alertmanager is usually the alerting engine; Grafana is primarily visualization (with optional alerts)

   ┌────────────────────┐
   │ Application Code   │
   │ (metrics via /metrics) 
   └─────────┬──────────┘
             │
             ▼
   ┌────────────────────┐
   │ Prometheus Server  │
   │ - Scrapes metrics  │
   │ - Stores TSDB      │
   │ - Evaluates rules  │
   └─────────┬──────────┘
             │ (PromQL API)
   ┌─────────▼──────────┐
   │      Grafana       │
   │ - Dashboards       │
   │ - Visualizations   │
   │ - Optional alerts  │
   └────────────────────┘
             │ (Alert rules firing)
             ▼
   ┌────────────────────┐
   │   Alertmanager     │
   │ - Dedup / Grouping │
   │ - Routing          │
   │ - Notifications    │
   └─────────┬──────────┘
             │
   ┌─────────▼──────────┐
   │ Slack / PagerDuty  │
   │ Email / SMS / Web  │
   └────────────────────┘







---

# Wrap Up

In this article we discussed the design for a metrics monitoring and alerting system. At a high level, we talked about the data collection, time-series database, alerts and visualization. We also dove into some of the important techniques and components, such as:

- Push versus pull model for collecting metrics data.
- Using Kafka to scale the system.
- Choosing the right time-series database.
- Using downsampling to reduce data size.
- Build versus buy options for alerting and visualization systems.

We went through a few iterations to refine the diagram, and our final design looks like this:
<img width="1283" height="405" alt="image" src="https://github.com/user-attachments/assets/edb06125-fdec-4698-9810-f4b089cd103c" />

In conclusion, designing a metrics monitoring and alerting system is a crucial step in ensuring the health and performance of any system or application. By carefully selecting the key metrics to monitor, collect and store data accurately, setting up effective alerts and notifications, and regularly reviewing and improving the system, it is possible to create a robust and reliable system that can help identify and resolve potential issues before they become critical.


## Additional resources :

https://www.statcan.gc.ca/en/data-science/network/monitoring-alerting-system

