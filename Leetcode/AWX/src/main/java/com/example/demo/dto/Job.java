package com.example.demo.dto;

import com.fasterxml.jackson.annotation.JsonInclude;
import com.fasterxml.jackson.annotation.JsonProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@JsonInclude(JsonInclude.Include.NON_NULL)
public class Job {

    @JsonProperty("id")
    private Integer id;

    @JsonProperty("job")
    private Integer jobId;

    @JsonProperty("status")
    private String status;

    @JsonProperty("created")
    private LocalDateTime created;

    @JsonProperty("modified")
    private LocalDateTime modified;

    @JsonProperty("stdout")
    private String stdResult;
}
