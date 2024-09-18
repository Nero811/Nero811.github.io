package com.example.demo.dto;

import com.fasterxml.jackson.annotation.JsonProperty;
import lombok.Data;

import java.time.LocalDateTime;
import java.util.Locale;

@Data
public class Template {
    @JsonProperty("id")
    private Integer id;

    @JsonProperty("type")
    private String type;

    @JsonProperty("created")
    private LocalDateTime created;

    @JsonProperty("modified")
    private LocalDateTime modified;

    @JsonProperty("last_job_run")
    private LocalDateTime lastJobRun;

    @JsonProperty("name")
    private String name;

    @JsonProperty("playbook")
    private String playbook;

    @JsonProperty("status")
    private String status;
}
