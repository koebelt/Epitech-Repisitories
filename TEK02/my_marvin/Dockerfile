FROM jenkins/jenkins:lts

# disable ui
ENV JAVA_OPS "-Djenkins.install.runSetupWizard=false -Dpermissive-script-security.enabled=true"
ENV CASC_JENKINS_CONFIG /var/jenkins_home/casc.yml
COPY plugins.txt /usr/share/jenkins/ref/plugins.txt
COPY my_marvin.yml /var/jenkins_home/casc.yml
COPY job_dsl.groovy /var/jenkins_home/job_dsl.groovy
RUN /usr/local/bin/install-plugins.sh < /usr/share/jenkins/ref/plugins.txt