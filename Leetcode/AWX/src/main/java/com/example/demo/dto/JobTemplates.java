package com.example.demo.dto;

import com.fasterxml.jackson.annotation.JsonProperty;
import lombok.Data;

import java.util.List;

@Data
public class JobTemplates {

    @JsonProperty("count")
    private Integer count;

    @JsonProperty("results")
    private List<Template> results;
}
