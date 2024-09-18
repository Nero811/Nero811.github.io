package com.example.demo.controller;

import ch.qos.logback.core.util.StringUtil;
import com.example.demo.dto.Job;
import com.example.demo.dto.JobTemplates;
import com.example.demo.dto.Token;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.*;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.client.RestTemplate;

import java.util.Objects;

@RestController
public class AwxController {

    @Autowired
    private RestTemplate restTemplate;

    @Value("${aws.api.v2.uri}")
    private String awxApiUri;

    @GetMapping("/launchTemplate")
    public ResponseEntity<Job> launchTemplate(@RequestParam Integer id) {
        String url = awxApiUri + "job_templates/" + id + "/launch/";
        String token = getToken();
        HttpHeaders httpHeaders = new HttpHeaders();
        httpHeaders.setContentType(MediaType.APPLICATION_JSON);
        httpHeaders.add("Authorization", "Bearer " + token);

        ResponseEntity<Job> response = restTemplate.exchange(url, HttpMethod.POST, new HttpEntity<>(httpHeaders), Job.class);
        Job result = Objects.requireNonNull(response.getBody());

        return ResponseEntity.ok(result);
    }

    @GetMapping("/getJobTemplates")
    public ResponseEntity<JobTemplates> getJobTemplates() {
        String url = awxApiUri + "/job_templates/";
        String token = getToken();
        HttpHeaders httpHeaders = new HttpHeaders();
        httpHeaders.add("Authorization", "Bearer " + token);

        ResponseEntity<JobTemplates> response = restTemplate.exchange(url, HttpMethod.GET, new HttpEntity<>(httpHeaders), JobTemplates.class);

        JobTemplates result = Objects.requireNonNull(response.getBody());

        return ResponseEntity.ok(result);
    }

    @GetMapping("/getJobById")
    public ResponseEntity<Job> getJobById(@RequestParam Integer id) {
        String url = awxApiUri + "jobs/" + id;
        String token = getToken();
        HttpHeaders httpHeaders = new HttpHeaders();
        httpHeaders.add("Authorization", "Bearer " + token);

        ResponseEntity<Job> response = restTemplate.exchange(url, HttpMethod.GET, new HttpEntity<>(httpHeaders), Job.class);

        Job result = Objects.requireNonNull(response.getBody());

        String stdout = getJobStd(id);

        if (StringUtil.notNullNorEmpty(stdout)) {
            result.setStdResult(stdout);
        }

        return ResponseEntity.ok(result);
    }

    @GetMapping("/getJobStd")
    public String getJobStd(@RequestParam Integer id) {
        String url = awxApiUri + "jobs/" + id + "/stdout?format=txt";
        String token = getToken();
        HttpHeaders httpHeaders = new HttpHeaders();
        httpHeaders.add("Authorization", "Bearer " + token);

        ResponseEntity<String> response = restTemplate.exchange(url, HttpMethod.GET, new HttpEntity<>(httpHeaders), String.class);

        return response.getBody();
    }


    @PostMapping("/getToken")
    public String getToken() {
        String url = awxApiUri + "tokens/";
        HttpHeaders httpHeaders = new HttpHeaders();
        httpHeaders.setContentType(MediaType.APPLICATION_JSON);
        httpHeaders.add("Authorization", "Basic " + "YWRtaW46YWRtaW4=");

        ResponseEntity<Token> response = restTemplate.exchange(url, HttpMethod.POST, new HttpEntity<>(httpHeaders), Token.class);

        String token = Objects.requireNonNull(response.getBody()).getToken();

        return token;
    }
}
